CXX = g++ -std=c++11
CC_FLAGS = -g
CC = ${CXX} ${CC_FLAGS} 
BUILD_DIR = build

all: tutrix.out
tutrix.out: ${BUILD_DIR}/main.o ${BUILD_DIR}/star.o ${BUILD_DIR}/map.o ${BUILD_DIR}/animation.o ${BUILD_DIR}/GamePause.o  ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Score.o
	${CC} ${BUILD_DIR}/main.o ${BUILD_DIR}/star.o ${BUILD_DIR}/map.o ${BUILD_DIR}/animation.o ${BUILD_DIR}/GamePause.o  ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Score.o -o ${BUILD_DIR}/tutrix.out -lsfml-graphics -lsfml-window -lsfml-system ; ${BUILD_DIR}/tutrix.out
${BUILD_DIR}/main.o: main.cpp Game.hpp
	${CC} -c main.cpp -o ${BUILD_DIR}/main.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/star.o : star.cpp star.hpp Const.hpp
	${CC} -c star.cpp -o ${BUILD_DIR}/star.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/map.o : map.cpp map.hpp Const.hpp
	${CC} -c map.cpp -o ${BUILD_DIR}/map.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/animation.o: animation.cpp animation.hpp Const.hpp
	${CC} -c animation.cpp -o ${BUILD_DIR}/animation.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/GamePause.o: GamePause.cpp GamePause.hpp Const.hpp
	${CC} -c GamePause.cpp -o ${BUILD_DIR}/GamePause.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/Player.o: Player.cpp Player.hpp Const.hpp map.hpp animation.hpp 
	${CC} -c Player.cpp  -o ${BUILD_DIR}/Player.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/Game.o: Game.cpp Game.hpp Player.hpp Score.hpp map.hpp GamePause.hpp star.hpp
	${CC} -c Game.cpp -o ${BUILD_DIR}/Game.o -lsfml-graphics -lsfml-window -lsfml-system
${BUILD_DIR}/Score.o: Score.cpp Score.hpp Const.hpp
	${CC} -c Score.cpp -o ${BUILD_DIR}/Score.o -lsfml-graphics -lsfml-window -lsfml-system
clean:
	rm -rf build/ && mkdir -p build