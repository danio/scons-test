import os
import platform
import string
import sys

# configuration setup
operatingSystem = platform.system().title()
if 'Windows' in operatingSystem:
	operatingSystem = 'Windows'
targetArch = 'x86'
compileBits = '32'
test = False

# Environment
if operatingSystem == 'Windows':
	root = os.getcwd()
	dupSrc = 1
else:
	root = os.getcwd() # set this...
	dupSrc = 0

# directories for objects and binaries
buildDir = os.path.join(root, 'build')
binDir = os.path.join(root, 'bin')

# shared environment settings
env = Environment(
	TARGET_ARCH=targetArch,
	CPPPATH=[os.getcwd()],
	LIBPATH=[buildDir]
    )

if operatingSystem == 'Linux':
	march = {'x86':'i686', 'x86_64':'x86-64'}

	env.Append(
		CPPDEFINES=['LINUX', ],
		CCFLAGS=['-m%s' % compileBits, '-pthread', '-march=%s' % march[targetArch]],
		LINKFLAGS=['-m%s' % compileBits, ]
		)
	env.Append(
		CCFLAGS=['-ggdb3', ],
		LINKFLAGS=['-ggdb3', ])
else: # Windows
	env.Append(CPPDEFINES=['WIN%s' % compileBits, 'WIN%s_LEAN_AND_MEAN'  % compileBits])
	dupSrc = 0
	env.Append(
		CPPDEFINES=['_DEBUG', ],
		CCFLAGS=['/EHsc', '/MDd', '/FC', ],
		LINKFLAGS=['/DEBUG']);

print 'compiling: arch=%s, os=%s, bits=%s, dupsrc=%d' % (targetArch, operatingSystem, compileBits, dupSrc)

projects=['module1', 'app']

for project in projects:
	variantDir = os.path.join(buildDir, project)
	projEnv = env.Clone()
	projEnv.Append(LIBPATH=[os.path.join(buildDir, 'module1')])
	projEnv.SConscript(os.path.join(project, 'SConscript'), exports='env buildDir binDir', variant_dir=variantDir, duplicate=dupSrc)
