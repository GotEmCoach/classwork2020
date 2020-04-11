GTEST_DIR=gtest
GTEST_SRC=${GTEST_DIR}/src/gtest-all.cc
TEST_SRC=test1.cpp
CXX=g++
CXX_FLAGS= -isystem gtest/include -isystem ../src -I${GTEST_DIR} -pthread
LD_FLAGS=libgtest.a
OBJS=prepend_test append_test removeFront_test removeFront_extended_test \
removeBack_test removeBack_extended_test remove_test search_test

all: libgtest.a $(OBJS)

$(OBJS): %: %.cpp
	$(CXX)  $(CXX_FLAGS) $(LD_FLAGS) -o $@.out $<

libgtest.a: gtest-all.o
	ar -rc libgtest.a gtest-all.o

gtest-all.o: ${GTEST_SRC}
	g++ $(CXX_FLAGS) -c ${GTEST_SRC}

clean:
	rm *.o
	rm *.out
	rm *.a

rebuild: clean all
