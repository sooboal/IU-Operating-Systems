mkdir folder1
date
sleep 3
mkdir folder2
date
sleep 3
touch folder1/root.txt
date
sleep 3
touch folder2/home.txt
ls -l / | sort -k6,8 > folder1/root.txt 
ls -l ~ | sort -k6,8 > folder2/home.txt
echo "------------------"
echo "root.txt info:"
cat folder1/root.txt
echo "------------------"
echo "folder1 info:"
ls folder1
echo "------------------"
echo "home.txt info:"
cat folder2/home.txt
echo "------------------"
echo "folder2 info:"
ls folder2
