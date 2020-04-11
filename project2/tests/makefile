CXX=g++
CXX_FLAGS= -isystem ../src -pthread
OBJS=enq_p1 enq_p2 deq_p1 deq_p2 isempty_test clear_test count_test

all: $(OBJS)

$(OBJS): %: %.cpp
	$(CXX)  $(CXX_FLAGS) -o $@.out $<

clean:
	rm *.out

rebuild: clean all
