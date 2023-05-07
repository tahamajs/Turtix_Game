CXX = g++ -std=c++11
CC_FLAGS = -g
CC = ${CXX} ${CC_FLAGS} 
BUILD_DIR = build
HEADERS_DIR=HederFiles
SOURCE_DIR = source
SFFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all:	${BUILD_DIR} tutrix.out
tutrix.out: ${BUILD_DIR}/main.o ${BUILD_DIR}/star.o ${BUILD_DIR}/map.o ${BUILD_DIR}/animation.o ${BUILD_DIR}/GamePause.o  ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Score.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/AudioClip.o ${BUILD_DIR}/MusicPlayer.o  ${BUILD_DIR}/Enemy.o
	${CC} ${BUILD_DIR}/main.o ${BUILD_DIR}/star.o ${BUILD_DIR}/map.o ${BUILD_DIR}/animation.o ${BUILD_DIR}/GamePause.o  ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Score.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/AudioClip.o ${BUILD_DIR}/MusicPlayer.o ${BUILD_DIR}/Enemy.o  -o tutrix.out ${SFFLAGS} ; ./tutrix.out
${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}
${BUILD_DIR}/main.o: ${SOURCE_DIR}/main.cpp ${HEADERS_DIR}/Game.hpp
	${CC} -c ${SOURCE_DIR}/main.cpp -o ${BUILD_DIR}/main.o ${SFFLAGS}

${BUILD_DIR}/star.o : ${SOURCE_DIR}/star.cpp ${HEADERS_DIR}/star.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/star.cpp -o ${BUILD_DIR}/star.o ${SFFLAGS}

${BUILD_DIR}/map.o : ${SOURCE_DIR}/map.cpp ${HEADERS_DIR}/map.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/map.cpp -o ${BUILD_DIR}/map.o ${SFFLAGS}

${BUILD_DIR}/animation.o: ${SOURCE_DIR}/animation.cpp ${HEADERS_DIR}/animation.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/animation.cpp -o ${BUILD_DIR}/animation.o ${SFFLAGS}

${BUILD_DIR}/GamePause.o: ${SOURCE_DIR}/GamePause.cpp ${HEADERS_DIR}/GamePause.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/GamePause.cpp -o ${BUILD_DIR}/GamePause.o ${SFFLAGS}

${BUILD_DIR}/Player.o: ${SOURCE_DIR}/Player.cpp ${HEADERS_DIR}/Player.hpp ${HEADERS_DIR}/Const.hpp ${HEADERS_DIR}/map.hpp ${HEADERS_DIR}/animation.hpp 
	${CC} -c ${SOURCE_DIR}/Player.cpp  -o ${BUILD_DIR}/Player.o ${SFFLAGS}

${BUILD_DIR}/Game.o: ${SOURCE_DIR}/Game.cpp ${HEADERS_DIR}/Game.hpp ${HEADERS_DIR}/Player.hpp ${HEADERS_DIR}/Score.hpp ${HEADERS_DIR}/map.hpp ${HEADERS_DIR}/GamePause.hpp ${HEADERS_DIR}/star.hpp ${HEADERS_DIR}/menu.hpp ${HEADERS_DIR}/AudioClip.hpp ${HEADERS_DIR}/MusicPlayer.hpp ${HEADERS_DIR}/Enemy.hpp
	${CC} -c ${SOURCE_DIR}/Game.cpp -o ${BUILD_DIR}/Game.o ${SFFLAGS}

${BUILD_DIR}/Score.o: ${SOURCE_DIR}/Score.cpp ${HEADERS_DIR}/Score.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/Score.cpp -o ${BUILD_DIR}/Score.o  ${SFFLAGS}

${BUILD_DIR}/menu.o: ${SOURCE_DIR}/menu.cpp ${HEADERS_DIR}/menu.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/menu.cpp -o ${BUILD_DIR}/menu.o ${SFFLAGS}

${BUILD_DIR}/AudioClip.o: ${SOURCE_DIR}/AudioClip.cpp ${HEADERS_DIR}/AudioClip.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/AudioClip.cpp -o ${BUILD_DIR}/AudioClip.o  ${SFFLAGS}

${BUILD_DIR}/MusicPlayer.o: ${SOURCE_DIR}/MusicPlayer.cpp ${HEADERS_DIR}/MusicPlayer.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/MusicPlayer.cpp -o ${BUILD_DIR}/MusicPlayer.o  ${SFFLAGS}

${BUILD_DIR}/Enemy.o : ${SOURCE_DIR}/Enemy.cpp ${HEADERS_DIR}/Enemy.hpp ${HEADERS_DIR}/Player.hpp ${HEADERS_DIR}/animation.hpp ${HEADERS_DIR}/map.hpp ${HEADERS_DIR}/AudioClip.hpp ${HEADERS_DIR}/Const.hpp
	${CC} -c ${SOURCE_DIR}/Enemy.cpp -o ${BUILD_DIR}/Enemy.o ${SFFLAGS}

clean:
	rm -rf build/ 
