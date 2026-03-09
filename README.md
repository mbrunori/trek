# Trek
**Trek** is a lightweight CLI tool that will allow you to navigate faster through directories.  
Instead of repeatedly typing long `cd` commands, Trek provides a simpler and quicker way to move across your filesystem directly from the terminal.
## Installation
For the installation you can clone the repository into the desired directory:
```
git clone https://github.com/mbrunori/trek.git
```
Then move to the trek directory, compile and install the code (remember to reaload the terminal to apply changes):
```
cd trek
make
sudo make install
source ~/bashrc
```
### Uninstall
To uninstall trek:
```
sudo make uninstall
source ~/bashrc
```
## Usage
To start the program, type `trek` in a terminal emuator.   
You can then navigate using:
- `j` and `k` to move up and down
- `h` and `ł` to move to the parent directory or to enter the selected directory
- `i` to exit Trek and change to the selected directory
