git clone https://github.com/devkitPro/3dstools.git
cd 3dstools
git switch cxi-stuff
./autogen.sh
./configure
make
mv cxitool ../
cd ..

git clone https://github.com/3DSGuy/Project_CTR.git
cd Project_CTR/makerom
make deps
make
mv bin/makerom ../../
cd ../../

git clone https://github.com/carstene1ns/3ds-bannertool.git
cd 3ds-bannertool
cmake -B build -DCMAKE_BUILD_TYPE=RelWithDebInfo
cmake --build build
mv build/bannertool ../
cd ../ 

sudo rm -r Project_CTR
sudo rm -r 3dstools
sudo rm -r 3ds-bannertool