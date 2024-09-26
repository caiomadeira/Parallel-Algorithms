# Stream Parallelism

The goal of this training is to teach basic knowledge about stream parallel programming in shared memory arquitectures.

The directory is organized as follows:
	`applications` contains the applications to be parallelized
	`scripts` contains scripts to locally install and setup OpenCV

# OpenCV

OpenCV is a video library used by several of the applications. 
You must locally install it and set up its path in your current session.
To do that we provided helper scripts in `scripts` directory:
	
- First run: `./install_libs`
- Whenever you want to compile or run code use: `source setup_ffmpeg_vars.sh` and also `source setup_opencv_vars.sh`
- You can confirm it worked by printing the contents: `echo $LD_LIBRARY_PATH`

# Deliverables

Each activity is formed by the parallelization of one applicaiton.
- Brief repoort describing the parallelization of each application. (up to 10 lines)
- Graph comparing the different application versions. X axis contains the number of parallel threads and Y axis the execution time. Tests must be executed at least 3 times and the standard deviation should be plotted.
- Brief discussion about the results explaining the results. (up to 20 lines)

# APIs for parallel programming
- SPar (you may find instructions in SPar_Manual.pdf)
- FastFlow (only pipeline and farm patterns)
- OneTBB (only pipeline and flow graph patterns)

# Suggested order of activities

1. hello
2. rgb-select
3. lane-detection
