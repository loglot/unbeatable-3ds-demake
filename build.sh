./3dsx-to-cia/cxitool unbeatable.3dsx unbeatable.cxi
./3dsx-to-cia/bannertool makebanner -i banner2.png -o unbeatable.bnr -a empty.wav
./3dsx-to-cia/makerom -v -f cia -o UNBEATABLE.cia -target t -i unbeatable.cxi:0:0 -ignoresign -icon unbeatable.smdh -banner unbeatable.bnr