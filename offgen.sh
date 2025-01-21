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

rm -rf dist run
for target in $(ls $TARGET | cut --delimiter='.' -f1 | uniq); do
    DIR=$(echo $target | cut --delimiter='_' -f2-)
    mkdir -p dist/$DIR
    export GEN=$(echo -n $target | tail -c1)
    if [[ $GEN -ge 4 ]]; then
        HACK="$HACK (Gen $GEN)"
    fi
    grep -f symbols.txt $target.map | tr -s ' ' | cut --delimiter=' ' -f2-3 > dist/$DIR/offsets.txt
    make -BC tools/inigen
    tools/inigen/inigen $target.elf dist/$DIR/custom_offsets.ini --code $CODE --name "$HACK"
    if [[ -f upr.jar && $GEN -ge 4 ]]; then
        SEEDS=1000
        if [ ! -f batch.jar ]; then
            wget https://github.com/champred/UPR-Android/releases/download/v0.5.1a/batch.jar
        fi
        mkdir -p run/$CONFIG
        cp dist/$DIR/custom_offsets.ini run/$CONFIG
        jar uf upr.jar -C run $CONFIG/custom_offsets.ini
        echo y | java -Xmx4608M -jar batch.jar 1 $SEEDS $target.gba run seed 319WQIEEjIBAAQABwCRAAKeBnsECQEACQACCQAuEgAAAAAABRi45ATkAYAICTIGBAIyAAUAEEZpcmUgUmVkIChVKSAxLjHHK9Hc48M4ig==
        sort --batch-size=$SEEDS run/*.log | uniq -c | node evoproc.js $SEEDS > dist/$DIR/evos.json
    fi
    cat dist/$DIR/offsets.txt | node -r fs -p "JSON.stringify(fs.readFileSync(0,'utf8').split(/\s+/).slice(0,-1).reduce((acc,val,ind,arr)=>acc[val]?acc:Object.assign(acc,{[arr[ind+1]]:Number(val)}),{}));" > dist/$DIR/offsets$SUFFIX.json
done