@echo off
mkdir antlr-cpp-runtime
pushd antlr-cpp-runtime

git init
git config core.sparsecheckout true
echo /runtime/Cpp > .git/info/sparse-checkout
git remote add origin https://github.com/antlr/antlr4.git
git pull --depth=1 origin master
git checkout master

popd
@echo OK