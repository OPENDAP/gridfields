# GridFields

For reference, see

 * Bill Howe, David Maier, "Algebraic Manipulation of Scientific Datasets", VLDB Journal 2005

 * Bill Howe, Model-Driven Data Transformation in the Physical Sciences, Doctoral Dissertation, Portland State University, 2006

# Directory structure
/src contains c++ source 

/gridfield contains python bindings implemented using SWIG and python support modules 

/gridfield_server is an XML-RPC server for evaluating remote gridfield expressions /vistrails_package is a package for the VisTrails workflow system

# Requirements
Python 2.4+ swig 1.3+ netcdf 3+ (with headers) VTK 4.2+ (optional, if vtk not detected through python, visualization components will not be built )

## Installation of the gridfield python package
Note: VTK headers are frequently installed in strange places. If you plan to use VTK, edit the setup.py file and change the value of vtkincl $ python setup.py build $ python setup.py install

##Installation of VisTrails Package

cp -LR vistrails_package/gridfield ~/.vistrails/userpackages cp vistrails_package/examples/gridfieldexample.xml $VISTRAILS/examples

Enable the package in VisTrails: Menu Edit > Preferences (Mac: Menu VisTrails > Preferences)

# Examples
A version tree showing how to use gridfields to access CORIE data is at vistrails_package/gridfieldexample.xml

# Build Instructions: Makefile
If you want to compile the library yourself (perhaps to compile bindings for a different language), you can modify the SWIG Makefile(s) in gridfield/ and the c++ Makefile in src/.

`cd gridfield`

edit Makefile so that libraries and include files # for Python and VTK are correct. # Also verify the compiler and associated settings. then:

`make gridfield make gfvis`

to test that gridfields can be imported in python, run python test.py # and verify that it generates simple output
