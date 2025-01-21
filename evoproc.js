const fs = require("fs");
const evos = fs.readFileSync(0, "utf8")
.split(/\r?\n/)
.slice(1, -1)
.map(ln => ln.trim().split('->'))
.reduce((acc, evo) => {
    const key = evo[0].split(' '), targets = [...evo[1].matchAll(/(\d+)=(\d+)/g)];
    if (targets.length == 0) {
        const val = {
            id: Number(evo[1]),
            perc: Math.floor((key[0]/process.argv[2]) * 10_000) / 100
        };
        if (acc[key[1]]) acc[key[1]].push(val)
        else acc[key[1]] = [val];
    } else {
        if (!acc[key[1]]) {
            const options = targets.reduce((acc, opt) => Object.assign(acc, {[opt[1]]: []}), {});
            acc[key[1]] = {
                options: Object.keys(options).map(Number),
                ...options
            };
        }

        for (let opt of targets) {
            if (acc[key[1]][opt[1]][opt[2]])
                acc[key[1]][opt[1]][opt[2]] += Number(key[0]);
            else
                acc[key[1]][opt[1]][opt[2]] = Number(key[0]);
        }
    }
    return acc;
}, {});

for (let e in evos) {
    if (evos[e].options) {
        for (let o of evos[e].options) {
            const targets = [];
            evos[e][o].forEach((num, tar) => {
                targets.push({
                    id: tar,
                    perc: Math.floor((num/process.argv[2]) * 10_000) / 100
                })
            });
            targets.sort((a, b) => b.perc-a.perc);
            evos[e][o].splice(0, Infinity, ...targets);
        }
    } else evos[e].sort((a, b) => b.perc-a.perc);
}

console.log(JSON.stringify(evos));