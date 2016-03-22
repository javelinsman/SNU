
all: compile jar run

compile:
	hadoop com.sun.tools.javac.Main WordCount.java

jar:
	jar cf WordCount.jar WordCount*.class
	rm -rf WordCount*.class

run:
	hadoop jar WordCount.jar WordCount ./input ./output
	hadoop fs -cat output/part-r-00000
	hadoop fs -get output/part-r-00000 output.txt

clean:
	rm -rf output*
	rm -rf *.jar
