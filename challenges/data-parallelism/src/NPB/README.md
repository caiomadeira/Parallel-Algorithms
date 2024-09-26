# The Kernels

Each directory is independent and contains its own implemented version of the kernels:

## Kernels

	EP - Embarrassingly Parallel, floating-point operation capacity
	MG - Multi-Grid, non-local memory accesses, short- and long-distance communication
	CG - Conjugate Gradient, irregular memory accesses and communication
	FT - discrete 3D fast Fourier Transform, intensive long-distance communication

# Software Requirements

*Warning: our tests were made with GCC-9 and ICC-19*

# How to Compile 

Enter the directory from the version desired and execute:

`$ make _BENCHMARK CLASS=_WORKLOAD`

_BENCHMARKs are: 
		
	EP, CG, MG, IS, FT, BT, SP and LU 
																										
_WORKLOADs are: 
	
	Class S: small for quick test purposes
	Class W: workstation size (a 90's workstation; now likely too small)	
	Classes A, B, C: standard test problems; ~4X size increase going from one class to the next	
	Classes D, E, F: large test problems; ~16X size increase from each of the previous Classes  


Command example:

`$ make ep CLASS=A`

# How to Execute

Binaries are generated inside the bin folder

Command example:
	
`$ ./bin/ep.A`