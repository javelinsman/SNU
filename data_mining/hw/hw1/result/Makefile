all: clean compile jar in_dist out_dist

compile:
	hadoop com.sun.tools.javac.Main IndegreeCounter.java
	hadoop com.sun.tools.javac.Main OutdegreeCounter.java
	hadoop com.sun.tools.javac.Main DegreeDistribution.java

jar:
	jar cf IndegreeCounter.jar IndegreeCounter*.class
	rm -rf IndegreeCounter*.class
	jar cf OutdegreeCounter.jar OutdegreeCounter*.class
	rm -rf OutdegreeCounter*.class
	jar cf DegreeDistribution.jar DegreeDistribution*.class
	rm -rf DegreeDistribution*.class

in: compile jar
	rm -rf ./output
	hadoop jar IndegreeCounter.jar IndegreeCounter ./problem.edge ./output
	hadoop fs -cat output/part-r-00000
	rm -f ./output_indeg.txt
	hadoop fs -get output/part-r-00000 output_indeg.txt

out: compile jar
	rm -rf ./output
	hadoop jar OutdegreeCounter.jar OutdegreeCounter ./problem.edge ./output
	hadoop fs -cat output/part-r-00000
	rm -f ./output_outdeg.txt
	hadoop fs -get output/part-r-00000 output_outdeg.txt

in_dist: in
	rm -rf ./output
	hadoop jar DegreeDistribution.jar DegreeDistribution ./output_indeg.txt ./output
	hadoop fs -cat output/part-r-00000
	rm -f ./output_indeg_dist.txt
	hadoop fs -get output/part-r-00000 output_indeg_dist.txt

out_dist: out
	rm -rf ./output
	hadoop jar DegreeDistribution.jar DegreeDistribution ./output_outdeg.txt ./output
	hadoop fs -cat output/part-r-00000
	rm -f ./output_outdeg_dist.txt
	hadoop fs -get output/part-r-00000 output_outdeg_dist.txt

clean:
	rm -rf output*
	rm -rf *.jar
