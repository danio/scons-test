import os
import platform
import string
import sys

projects=['module1', 'app']

# configuration setup
operatingSystem = platform.system().title()
if 'Windows' in operatingSystem:
	operatingSystem = 'Windows'
targetArch = 'x86'
compileBits = '32'
test = False

# Environment
# Using os.getcwd() is just for demonstration purposes. In practice you might get it from an environment variable, relative path, ...
outputDir = os.getcwd() # Set the directory for building into. Use a local disk for speed.
if operatingSystem == 'Windows':
	dupSrc = 1
else:
	dupSrc = 0

# custom command line options
buildDebug = False
optParams = ARGUMENTS.get('opt', None)
if optParams:
	buildDebug = 'debug' in optParams

# directories for objects and binaries
if buildDebug: # If you use python 2.5 or above you can use the nicer "a if test else b" syntax here
	buildSubDir = 'debug'
else:
	buildSubDir = 'release'
buildDir = os.path.join(outputDir, 'build', buildSubDir)
binDir = os.path.join(outputDir, 'bin', buildSubDir)

# shared environment settings
env = Environment(
	TARGET_ARCH=targetArch,
	CPPPATH=[Dir('.')],
	LIBPATH=[buildDir]
	)

if operatingSystem == 'Linux':
	march = {'x86':'i686', 'x86_64':'x86-64'}

	env.Append(
		CCFLAGS=['-m%s' % compileBits, '-pthread', '-march=%s' % march[targetArch]],
		LINKFLAGS=['-m%s' % compileBits, ]
		)
	if buildDebug:
		env.Append(CCFLAGS=['-ggdb3'], LINKFLAGS=['-ggdb3'] )
	else:
		env.Append(CPPDEFINES=['-DNDEBUG'])
else: # Windows
	env.Append(CPPDEFINES=['WIN%s' % compileBits, 'WIN%s_LEAN_AND_MEAN'  % compileBits])
	dupSrc = 0
	env.Append(
		CCFLAGS=['/EHsc', '/FC', '/sdl', '/bigobj', ],
		);
	env.Append(LINKFLAGS=['/DEBUG']) #this generates PDB -> http://msdn.microsoft.com/en-us/library/xe4t6fc1.aspx. Note that I want pdb in release mode for post-release debugging but you may not...
	if buildDebug:
		env.Append(
			CPPDEFINES=['_DEBUG'],
			CCFLAGS=['/MDd', '/Od', '/RTC1', ])
	else:
		env.Append(
			CPPDEFINES=['NDEBUG'],
			CCFLAGS=['/MD', '/O2', '/Oi', '/GL', ],
			LINKFLAGS=['/LTCG ']) # Microsoft recommend linking with LTCG when GL turned on to improve build performance

print 'compiling: arch=%s, os=%s, bits=%s, dupsrc=%d' % (targetArch, operatingSystem, compileBits, dupSrc)

for project in projects:
	variantDir = os.path.join(buildDir, project)
	SConscript(os.path.join(project, 'SConscript'), exports='env buildDir binDir', variant_dir=variantDir, duplicate=dupSrc)
