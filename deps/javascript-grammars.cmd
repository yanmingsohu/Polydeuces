@echo off
mkdir javascript-grammars
cd javascript-grammars

git init
git config core.sparsecheckout true
echo /javascript > .git/info/sparse-checkout
git remote add origin https://github.com/antlr/grammars-v4.git
git pull --depth=1 origin master
git checkout master

@echo OK