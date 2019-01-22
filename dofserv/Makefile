TARGET = dof_serv

CC  = gcc
CXX = g++

SOURCES  = main.cpp \
					 handler.cpp \
					 json_parser.cpp \
					 db_work.cpp
					 
LDFLAGS  = -levent -ljansson -lmongoc-1.0 -lbsoncxx -lmongocxx -L/usr/local/lib
CFLAGS   = -I/usr/local/include -I/usr/local/include/mongocxx/v_noabi -I/usr/local/include/libmongoc-1.0 -I/usr/local/include/bsoncxx/v_noabi -I/usr/local/include/libbson-1.0
CXXFLAGS = -std=c++11 $(CFLAGS)

all: $(TARGET)

.PHONY: all clean

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)
