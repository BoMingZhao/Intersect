# 软件工程第一次作业

test为单元测试文件夹，其中IntersectTest1,2,3分别对应三个关键函数：求两条直线间交点，求一条直线和一个圆的交点，求两个圆的交点。

源代码在src文件夹下，bin文件夹用来进行命令行测试，命令行格式为：intersect.exe -i input.txt -o output.txt

（本代码实现了附加题要求，但由于采用暴力做法，性能分部分测试应该是无法完成的）

扫描线做法也push上来了，但是发现这种扫描线无法处理多直线同交点的情况，会T。因此为了不影响性能注释了，忘大佬指教扫描线的正确写法。