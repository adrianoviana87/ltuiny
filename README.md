# ltuiny

a simple text-based utility to add a transaction to a [ledger](https://www.ledger-cli.org/) file.

## Is it ready yet?
The project is sill under development but it can already add transactions to a fixed ledger file named `data.dat` on the current directory.

## Dependencies
* cmake >= 3.5
* c++17 compiler
* [FTXUI](https://github.com/ArthurSonzogni/FTXUI)
  * I have to include this dependency as a submodule or something like that. For now, you can download the FTXUI repository and install the library.
  
## How to build
```sh
git clone https://github.com/adrianoviana87/ltuiny
cd ltuiny
mkdir build
cd build
cmake ..
cmake --build .
```
