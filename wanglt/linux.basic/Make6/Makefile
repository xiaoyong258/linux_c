.IPHONY:all

A = 1 3 5 7 9 11 13 15 17 19
B = $(foreach i,$(A),$(addprefix 0.,$(i)))
C = $(foreach i,$(A),$(addsuffix .0,$(i)))

all:
	@echo "A = $(A)"
	@echo "B = $(B)"
	@echo "C = $(C)"

