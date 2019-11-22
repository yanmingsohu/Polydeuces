@echo off
mkdir test262
cd test262

git init
git config core.sparsecheckout true
echo /test > .git/info/sparse-checkout
echo /docs >> .git/info/sparse-checkout
echo /*.md >> .git/info/sparse-checkout
git remote add origin https://github.com/tc39/test262.git
git pull --depth=1 origin master
git checkout master

@echo OK