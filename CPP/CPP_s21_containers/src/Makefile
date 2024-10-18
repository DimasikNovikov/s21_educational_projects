CXXFLAGS = -Wall -Wextra -Werror -std=c++17
LDFLAGS = -lgtest
TEST_SOURCE = $(wildcard Tests/*.cc)

all: test

test: $(TEST_SOURCE)
	$(CXX) $(CXXFLAGS) $^ $(LDFLAGS) -o $@

gcov_report: $(TEST_SOURCE)
	$(CXX) $(CXXFLAGS) --coverage $^ $(LDFLAGS) -o test_containers
	./test_containers
	lcov -o test_containers.info -c -d .
	genhtml -o report test_containers.info


clean:
	rm -f test test_containers
	rm -rf report *.gcda *.gcno *.info