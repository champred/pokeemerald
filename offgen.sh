#!/bin/bash

HACK="MAX"
CONFIG=com/dabomstew/pkrandom/config
DIR=${GAME_VERSION:-`pwd`}

case ${DIR,,} in
*firered)
TARGET="pokefirered*"
SUFFIX="_fr"
CODE="BPRE"
HACK="FireRed $HACK"
;;
*emerald)
TARGET="pokeemerald"
SUFFIX="_em"
CODE="BPEE"
HACK="Emerald $HACK"
;;
esac

rm -rf dist
mkdir -p dist/$CONFIG
for target in $(ls $TARGET | cut --delimiter='.' -f1 | uniq); do
    DIR=$(echo $target | cut --delimiter='_' -f2-)
    mkdir dist/$DIR
    GEN=$(echo $target | cut --delimiter='_' -f3)
    if [[ -n $GEN ]]; then
        HACK="$HACK+$GEN.Dex"
    fi
    grep -f symbols.txt $target.map | tr -s ' ' | cut --delimiter=' ' -f2-3 > dist/$DIR/offsets.txt
    tools/inigen/inigen $target.elf dist/$CONFIG/custom_offsets.ini --code $CODE --name "$HACK"
    jar uf upr.jar -C dist $CONFIG/custom_offsets.ini
    cp upr.jar dist/$DIR
    cat dist/$DIR/offsets.txt | node -r fs -p "JSON.stringify(fs.readFileSync(0,'utf8').split(/\s+/).slice(0,-1).reduce((acc,val,ind,arr)=>acc[val]?acc:Object.assign(acc,{[arr[ind+1]]:Number(val)}),{}));" > dist/$DIR/offsets$SUFFIX.json
done