./3dsx-to-cia/bannertool makebanner -i banner2.png -o unbeatable.bnr -a empty.wav
./3dsx-to-cia/cxitool unbeatable.3dsx unbeatable.cxi -b unbeatable.bnr
./3dsx-to-cia/makerom -v -f cia -o UNBEATABLE.cia -target t -i unbeatable.cxi:0:0 -ignoresign