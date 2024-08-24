Compiling with `make release` will also generate an .ini file that can be used to build the Universal Pokémon Randomizer ZX 4.6.0 for the purpose of randomizing Pokeemerald decomp hacks. Provided in this branch, inigen when built from unmodified code will produce an .ini file containing text identical to that of the "Emerald (U)" section of "gen3_offsets.ini" in the randomizer.

[**It is important to read the inigen notes because the randomizer uses binary patches, thus some symbols must remain at the same address as vanilla Emerald**](tools/inigen/inigen.c#L735-L854)

Credit to PikalaxALT and ProjectRevoTPP for inigen.


# Pokémon Emerald

This is a decompilation of Pokémon Emerald.

It builds the following ROM:

* [**pokeemerald.gba**](https://datomatic.no-intro.org/index.php?page=show_record&s=23&n=1961) `sha1: f3ae088181bf583e55daf962a92bb46f4f1d07b7`

To set up the repository, see [INSTALL.md](INSTALL.md).

For contacts and other pret projects, see [pret.github.io](https://pret.github.io/).
