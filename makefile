CXX = g++ -std=c++11
CC_FLAGS = -g
CC = ${CXX} ${CC_FLAGS} 
BUILD_DIR = build
SFFLAGS = -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio
all:${BUILD_DIR} tutrix.out 
${BUILD_DIR}:
	mkdir -p ${BUILD_DIR}
tutrix.out: ${BUILD_DIR}/main.o ${BUILD_DIR}/star.o ${BUILD_DIR}/map.o ${BUILD_DIR}/animation.o ${BUILD_DIR}/GamePause.o  ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Score.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/AudioClip.o ${BUILD_DIR}/MusicPlayer.o  ${BUILD_DIR}/Enemy.o
	${CC} ${BUILD_DIR}/main.o ${BUILD_DIR}/star.o ${BUILD_DIR}/map.o ${BUILD_DIR}/animation.o ${BUILD_DIR}/GamePause.o  ${BUILD_DIR}/Player.o ${BUILD_DIR}/Game.o ${BUILD_DIR}/Score.o ${BUILD_DIR}/menu.o ${BUILD_DIR}/AudioClip.o ${BUILD_DIR}/MusicPlayer.o ${BUILD_DIR}/Enemy.o  -o ${BUILD_DIR}/tutrix.out ${SFFLAGS} ; ${BUILD_DIR}/tutrix.out

${BUILD_DIR}/main.o: main.cpp Game.hpp
	${CC} -c main.cpp -o ${BUILD_DIR}/main.o ${SFFLAGS}

${BUILD_DIR}/star.o : star.cpp star.hpp Const.hpp
	${CC} -c star.cpp -o ${BUILD_DIR}/star.o ${SFFLAGS}

${BUILD_DIR}/map.o : map.cpp map.hpp Const.hpp
	${CC} -c map.cpp -o ${BUILD_DIR}/map.o ${SFFLAGS}

${BUILD_DIR}/animation.o: animation.cpp animation.hpp Const.hpp
	${CC} -c animation.cpp -o ${BUILD_DIR}/animation.o ${SFFLAGS}

${BUILD_DIR}/GamePause.o: GamePause.cpp GamePause.hpp Const.hpp
	${CC} -c GamePause.cpp -o ${BUILD_DIR}/GamePause.o ${SFFLAGS}

${BUILD_DIR}/Player.o: Player.cpp Player.hpp Const.hpp map.hpp animation.hpp 
	${CC} -c Player.cpp  -o ${BUILD_DIR}/Player.o ${SFFLAGS}

${BUILD_DIR}/Game.o: Game.cpp Game.hpp Player.hpp Score.hpp map.hpp GamePause.hpp star.hpp menu.hpp AudioClip.hpp MusicPlayer.hpp Enemy.hpp
	${CC} -c Game.cpp -o ${BUILD_DIR}/Game.o ${SFFLAGS}

${BUILD_DIR}/Score.o: Score.cpp Score.hpp Const.hpp
	${CC} -c Score.cpp -o ${BUILD_DIR}/Score.o  ${SFFLAGS}

${BUILD_DIR}/menu.o: menu.cpp menu.hpp Const.hpp
	${CC} -c menu.cpp -o ${BUILD_DIR}/menu.o ${SFFLAGS}

${BUILD_DIR}/AudioClip.o: AudioClip.cpp AudioClip.hpp Const.hpp
	${CC} -c AudioClip.cpp -o ${BUILD_DIR}/AudioClip.o  ${SFFLAGS}

${BUILD_DIR}/MusicPlayer.o: MusicPlayer.cpp MusicPlayer.hpp Const.hpp
	${CC} -c MusicPlayer.cpp -o ${BUILD_DIR}/MusicPlayer.o  ${SFFLAGS}

${BUILD_DIR}/Enemy.o : Enemy.cpp Enemy.hpp Player.hpp animation.hpp map.hpp AudioClip.hpp Const.hpp
	${CC} -c Enemy.cpp -o ${BUILD_DIR}/Enemy.o ${SFFLAGS}

clean:
	rm -rf build/ 
	
	
	
