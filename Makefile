CXXFLAGS= -g -std=c++11
OBJS=test.o alphabet_keyboard_move.o class_practice.o find_middle.o spell_word.o sort_str_dict.o island_prob_alive.o coin_sum.o bst_op.o miss_number.o interview.o binary_tree.o
PROGM=$(OBJS:%.o=%)

default: all

all: ${PROGM}

clean:
	rm -rf ${OBJS} ${PROGM}
