rem 复制LeetCode题解到目录下
robocopy  G:\CodeBlock\LeetCode G:\GitHub\MyCode\LeetCode *.h

rem 向github提交代码变动
G：
cd G:\GitHub\MyCode
git checkout main
git add .
git commit -m "git自动提交"
git push origin main