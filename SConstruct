import os
import platform
import string
import sys

# configuration setup
compiler = 'gcc44'
operatingSystem = platform.system().title()
if 'Windows' in operatingSystem:
	operatingSystem = 'Windows'
	compiler = 'vc11'
targetArch = 'x86'
compileBits = '32'
test = False

# Environment
if operatingSystem == 'Windows':
	root = os.getcwd() #os.path.join('D:/', 'sconstest2')
else:
	root = '' # set this...
	sys.exit()
dupSrc = 1

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

print 'compiling: arch=%s, os=%s, comp=%s, bits=%s, dupsrc=%d' % (targetArch, operatingSystem, compiler, compileBits, dupSrc)

projects=['lib', 'app']

for project in projects:
	#VariantDir(buildDir, project)
	#SConscript(os.path.join(project, 'SConscript'), exports='env binDir', variant_dir=buildDir, duplicate=dupSrc)
	projEnv = env.Clone()
	projEnv.SConscript(os.path.join(project, 'SConscript'), exports='env binDir', variant_dir=buildDir, duplicate=dupSrc)
