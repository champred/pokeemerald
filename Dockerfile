from ubuntu
env GAME_VERSION=EMERALD
env GAME_REVISION=0
env GAME_LANGUAGE=ENGLISH
run apt-get update && apt-get install -y --no-install-recommends\
    build-essential\
    git\
    libpng-dev\
    gcc-arm-none-eabi\
    binutils-arm-none-eabi\
    libcapstone-dev\
    ca-certificates\
    && rm -rf /var/lib/apt/lists/* && apt-get clean
copy . pokeemerald
run git clone https://github.com/pret/agbcc
run cd agbcc && ./build.sh && ./install.sh ../pokeemerald
workdir pokeemerald
volume dist
cmd make -j$(nproc) && cp pokeemerald.gba dist
