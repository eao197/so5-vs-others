# so5-vs-others
Short examples of SObjectizer-5 in comparison with other actor/concurrency tools

# Obtaining and Building

## Prerequisites

For building SObjectizer-5 and examples it is necessary to have Ruby (with `rake`) and [Mxx_ru](https://sourceforge.net/projects/mxxru/) build tool.

To install Mxx\_ru:
```
gem install Mxx_ru
```
Note: Mxx\_ru 1.6.10 or above is required. If you have older version it is necessary to update Mxx\_ru:
```
gem update Mxx_ru
```
Note: some Linux distros have Ruby without `rake` (Ubuntu for example). In such distros `rake` should be installed separatelly:
```
suto apt-get install rake
```
## C++ Compilers

These examples have been tested under GNU C++ 5.2-5.2, clang 3.6-3.7 and Visual C++ 14.0.

## Obtaining

```
git clone https://github.com/eao197/so5-vs-others
cd so5-vs-others
mxxruexternals
```

## Building

If you have only one compiler accessible via `PATH` then Mxx_ru will try to detect it automatically. In such case the following commands will be enough:
```
cd so5-vs-others/src
ruby build.rb
```
Compiled versions of SObjectizer and examples will be placed into `target/release` subdirectory.

If you have several different compilers (gcc and clang for example) it is necessary to set `MXX_RU_CPP_TOOLSET` environment variable:
```
export MXX_RU_CPP_TOOLSET=gcc_linux
cd so5-vs-others/src
ruby build.rb
```
Or
```
export MXX_RU_CPP_TOOLSET=clang_freebsd
cd so5-vs-others/src
ruby build.rb
```

## Running Examples

On Unixes (Linux/FreeBSD/MacOSX):
```
cd so5-vs-others/src
ruby build.rb
export LD_LIBRARY_PATH=$PWD/target/release
./target/release/habrhabr_go_vs_d_fibonacci
```
On Windows:
```
cd so5-vs-others/src
ruby build.rb
target\release\habrhabr_go_vs_d_fibonacci
```

## Yet Again The Full Sequence :)

On Unixes (Linux/FreeBSD/MacOSX):
```
git clone https://github.com/eao197/so5-vs-others
cd so5-vs-others
mxxruexternals
cd src
ruby build.rb
export LD_LIBRARY_PATH=$PWD/target/release
./target/release/habrhabr_go_vs_d_fibonacci
...
```
On Windows:
```
git clone https://github.com/eao197/so5-vs-others
cd so5-vs-others
mxxruexternals
cd src
ruby build.rb
target\release\habrhabr_go_vs_d_fibonacci
...
```
## Building of a Specific Example

If you want to build just one specific example do steps like shown bellow:
```
cd so5-vs-others/src
ruby samples/habrhabr_go_vs_d_fibonacci
```
