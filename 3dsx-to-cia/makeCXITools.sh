git clone https://github.com/devkitPro/3dstools.git
cd 3dstools
git switch cxi-stuff
./autogen.sh
./configure
make
mv cxitool ../
cd ..
sudo rm -r 3dstools

git clone https://github.com/3DSGuy/Project_CTR.git
cd Project_CTR/makerom
make deps
make
mv bin/makerom ../../
cd ../../
sudo rm -r Project_CTR
