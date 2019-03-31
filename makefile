#a: a.c  
#	gcc $^ -o $@
#.PHONY:clean
#	clean rm a
	#.o依赖.s,.s依赖.i,.i依赖.c
#b: b.o 
#	gcc b.o -o b
#b.o:b.s
#	gcc-C b.s -o b.o
#b.s:b.i
#	gcc -S b.i -o b.s
#b.i:b.c
#	gcc -E b.c -o b.i
#a:a.o
#	gcc a.o -o a
#a.o:a.c
#	gcc -c  a.c -o a.o
#	这个all编译不出来
#all:a.c b.c
#a:a.c
#	gcc a.c -o a
#b:b.c
#	gcc b.c -o b
#一个将两个点O文件生成.c文件
#src=$(wildcard./*.c)
#obj=$(patsubst%c,%o,$(src))
#.PHONY:$(bin)
#	bin=./a
#$(bin):$(obj)
#	gcc $^ -o $@
#	%o %c
#	gcc -c $< -o $@
#all:a b
#	a:a.c
#	gcc a.c -o a
#b:b.c
#	gcc a.c -o b
	#makefile中不能直接写变量名要用$(),将变量名扩起来
	#预定义变量$@:指的是冒号左边的目标对象$^指的是所有的依赖对象$<指的是依赖对象第一个
	#目标对象:依赖对象
	#%通配符匹配任意字符串,
#main:main.o
#	gcc main.o -o main 
#main.o:main.c
#	gcc main.c -o main.o
#	对makefile进行减少,bin 为要生成的程序bin,obj为依赖对象,源码文件src
#	%.o在这个程序相当度找到.o文件为mian.o而%.c是匹配main.c
#	如果obj里面有main.o和chlid.o都会生成自己的.o文件
#	这个中的$<只找第一个依赖对象
#	.PHONY声明伪对象,不管目标对象是否存在,不管目标对象是否最新
#	每次都要重新执行生成规则

#	bin=./main
#	obj=./main.o child.o
#	src=./main.c
#.PHONY: $(bin)
#$(bin):$(obj)
#	gcc $^ -o $@    #相当于gcc -main.o -o main
#%.o:%.c
#	gcc -c $< -o $@  #相当于 gcc -c main.c -o main.o 
#	
#clean:
#	rm $(bin) $(obj)
bin=./main 
src=$(wildcard ./*.c)#wildcard为关键字命令获取当前目录下以.c结尾的文件名,用$()表示让它执行这个命令
obj=$(patsubst %.o, %.c, $(src))#patsubst命令将src当中内容把.c替换成.o
#若当前目录下有main.c和child.c则经过这个命令就成了main.o和child.o
$(bin):$(obj)
	gcc $^ -o $@
%.o:%.c
	gcc -c $< -o $@
.PHONY :clean
	rm $(bin) $(obj)

