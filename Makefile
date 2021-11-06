CC = g++
AR = ar
APP_CCFLAGS = -c -std=c++17
APP_CCINCLUDE = -I src/

APP_SRC_FILES := $(shell find src/ -name *.cpp)
APP_OBJECT_FILES := $(patsubst src/%.cpp, bin-int/%.o, $(APP_SRC_FILES))

$(APP_OBJECT_FILES) : bin-int/%.o : $(APP_SRC_FILES)
	mkdir -p $(@D)
	$(CC) $(APP_CCFLAGS) $(APP_CCINCLUDE) -o $@ $(patsubst bin-int/%.o, src/%.cpp, $@)

bin/raytracing_engine: $(APP_OBJECT_FILES)
	mkdir -p $(@D)
	$(CC) -o $@ $^

run: bin/raytracing_engine
	./$^

clean:
	rm -rf bin-int
	rm -rf bin