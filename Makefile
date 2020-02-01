.PHONY = all clean

all: index.thinlto.ll static_build

# Essentially, these are .bc files, but it's useful to call them .s in order to
# avoid collisions with the re-assembled .bc files below.
%.s: %.c
	clang -c -flto=thin -O1 $< -o $@

%.ll: %.s
	llvm-dis $< -o $@

%.bc: %.ll
	llvm-as $< -o $@

index.thinlto.ll: main.bc sub1.bc sub2.bc sub21.bc sub22.bc sub23.bc workload.bc
	llvm-lto --thinlto -o index main.bc sub1.bc sub2.bc sub21.bc sub22.bc sub23.bc workload.bc
	llvm-dis -o index.thinlto.ll index.thinlto.bc

static_build: main.ll sub1.ll sub2.ll sub21.ll sub22.ll sub23.ll workload.ll
	clang -O1 -o $@ $^
	./$@

clean:
	rm -f *.s *.ll *.bc
