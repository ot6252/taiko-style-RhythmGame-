#include <bangtal>

using namespace bangtal;

int main() 
{
	setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);		// 인벤토리, 메세지 기능 제거
	setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);

	auto sound = Sound::create("Audios/GO MY WAY!!.mp3");	
	auto scene = Scene::create("메인화면", "images/메인화면.jpg");	
	auto sceneEnd = Scene::create("감사합니다", "images/감사합니다.jpg");
	auto timer = Timer::create(0.01f);
	auto comboT = Timer::create(0);
	showTimer(comboT);

	auto field = Object::create("images/field.png", scene, 0, 400);
	auto drum = Object::create("images/북.png", scene, 160, 410);
	auto great = Object::create("images/great.png", scene, 160, 410);
	auto combobreak = Object::create("images/combobreak.png", scene, 160, 480);
	great->hide();
	combobreak->hide();
	ObjectPtr RNote[48];	
	ObjectPtr BNote[48];
	int RNoteX[48];			
	int BNoteX[48];
	auto combo = 0;

	BNote[0] = Object::create("images/blue.png", scene, 2500, 450);
	BNoteX[0] = 2500;
	BNote[1] = Object::create("images/blue.png", scene, 3140, 450);
	BNoteX[1] = 3140;
	BNote[2] = Object::create("images/blue.png", scene, 3780, 450);
	BNoteX[2] = 3780;
	BNote[3] = Object::create("images/blue.png", scene, 4100, 450);
	BNoteX[3] = 4100;
	BNote[4] = Object::create("images/blue.png", scene, 4420, 450);
	BNoteX[4] = 4420;
	BNote[5] = Object::create("images/blue.png", scene, 4740, 450);
	BNoteX[5] = 4740;
	BNote[6] = Object::create("images/blue.png", scene, 5060, 450);
	BNoteX[6] = 5060;
	BNote[7] = Object::create("images/blue.png", scene, 5700, 450);
	BNoteX[7] = 5700;
	BNote[8] = Object::create("images/blue.png", scene, 6180, 450);
	BNoteX[8] = 6180;
	BNote[9] = Object::create("images/blue.png", scene, 6360, 450);
	BNoteX[9] = 6360;
	BNote[10] = Object::create("images/blue.png", scene, 6840, 450);
	BNoteX[10] = 6840;
	BNote[11] = Object::create("images/blue.png", scene, 7000, 450);
	BNoteX[11] = 7000;
	BNote[12] = Object::create("images/blue.png", scene, 7320, 450);
	BNoteX[12] = 7320;
	BNote[13] = Object::create("images/blue.png", scene, 7640, 450);
	BNoteX[13] = 7640;
	BNote[14] = Object::create("images/blue.png", scene, 7680, 450);
	BNoteX[14] = 7680;
	BNote[15] = Object::create("images/blue.png", scene, 7720, 450);
	BNoteX[15] = 7720;
	BNote[16] = Object::create("images/blue.png", scene, 7760, 450);
	BNoteX[16] = 7760;
	RNote[0] = Object::create("images/red.png", scene, 8920, 450);
	RNoteX[0] = 8920;
	RNote[1] = Object::create("images/red.png", scene, 9080, 450);
	RNoteX[1] = 9080;
	RNote[2] = Object::create("images/red.png", scene, 9720, 450);
	RNoteX[2] = 9720;
	RNote[3] = Object::create("images/red.png", scene, 10040, 450);
	RNoteX[3] =10040;
	RNote[4] = Object::create("images/red.png", scene, 10200, 450);
	RNoteX[4] = 10200;
	RNote[5] = Object::create("images/red.png", scene, 10360, 450);
	RNoteX[5] = 10360;
	RNote[6] = Object::create("images/red.png", scene, 10840, 450);
	RNoteX[6] = 10840;
	RNote[7] = Object::create("images/red.png", scene, 11160, 450);
	RNoteX[7] = 11160;
	RNote[8] = Object::create("images/red.png", scene, 11480, 450);
	RNoteX[8] = 11480;
	RNote[9] = Object::create("images/red.png", scene, 11720, 450);
	RNoteX[9] = 11720;
	RNote[10] = Object::create("images/red.png", scene, 11960, 450);
	RNoteX[10] = 11960;
	RNote[11] = Object::create("images/red.png", scene, 12120, 450);
	RNoteX[11] = 12120;
	RNote[12] = Object::create("images/red.png", scene, 12160, 450);
	RNoteX[12] = 12160;
	RNote[13] = Object::create("images/red.png", scene, 12200, 450);
	RNoteX[13] = 12200;
	RNote[14] = Object::create("images/red.png", scene, 12760, 450);
	RNoteX[14] = 12760;
	RNote[15] = Object::create("images/red.png", scene, 13400, 450);
	RNoteX[15] = 13400;
	RNote[16] = Object::create("images/red.png", scene, 14080, 450);
	RNoteX[16] = 14080;
	RNote[17] = Object::create("images/red.png", scene, 14720, 450);
	RNoteX[17] = 14720;
	RNote[18] = Object::create("images/red.png", scene, 15040, 450);
	RNoteX[18] = 15040;
	RNote[19] = Object::create("images/red.png", scene, 15360, 450);
	RNoteX[19] = 15360;
	RNote[20] = Object::create("images/red.png", scene, 16000, 450);
	RNoteX[20] = 16000;
	RNote[21] = Object::create("images/red.png", scene, 16640, 450);
	RNoteX[21] = 16640;
	RNote[22] = Object::create("images/red.png", scene, 17280, 450);
	RNoteX[22] = 17280;
	RNote[23] = Object::create("images/red.png", scene, 17600, 450);
	RNoteX[23] = 17600;
	RNote[24] = Object::create("images/red.png", scene, 17680, 450);
	RNoteX[24] = 17680;
	RNote[25] = Object::create("images/red.png", scene, 17840, 450);
	RNoteX[25] = 17840;
	RNote[26] = Object::create("images/red.png", scene, 18160, 450);
	RNoteX[26] = 18160;
	BNote[17] = Object::create("images/blue.png", scene, 18480, 450);
	BNoteX[17] = 18480;
	RNote[27] = Object::create("images/red.png", scene, 18800, 450);
	RNoteX[27] = 18800;
	BNote[18] = Object::create("images/blue.png", scene, 19120, 450);
	BNoteX[18] = 19120;
	RNote[28] = Object::create("images/red.png", scene, 19440, 450);
	RNoteX[28] = 19440;
	BNote[19] = Object::create("images/blue.png", scene, 19760, 450);
	BNoteX[19] = 19760;
	RNote[29] = Object::create("images/red.png", scene, 20080, 450);
	RNoteX[29] = 20080;
	RNote[30] = Object::create("images/red.png", scene, 20240, 450);
	RNoteX[30] = 20240;
	RNote[31] = Object::create("images/red.png", scene, 20400, 450);
	RNoteX[31] = 20400;
	RNote[32] = Object::create("images/red.png", scene, 20560, 450);
	RNoteX[32] = 20560;
	RNote[33] = Object::create("images/red.png", scene, 20720, 450);
	RNoteX[33] = 20720;
	BNote[20] = Object::create("images/blue.png", scene, 21040, 450);
	BNoteX[20] = 21040;
	RNote[34] = Object::create("images/red.png", scene, 21360, 450);
	RNoteX[34] = 21360;
	BNote[21] = Object::create("images/blue.png", scene, 21680, 450);
	BNoteX[21] = 21680;
	RNote[35] = Object::create("images/red.png", scene, 22000, 450);
	RNoteX[35] = 22000;
	RNote[36] = Object::create("images/red.png", scene, 22320, 450);
	RNoteX[36] = 22320;
	RNote[37] = Object::create("images/red.png", scene, 22720, 450);
	RNoteX[37] = 22720;
	RNote[38] = Object::create("images/red.png", scene, 22800, 450);
	RNoteX[38] = 22800;
	RNote[39] = Object::create("images/red.png", scene, 22960, 450);
	RNoteX[39] = 22960;
	BNote[22] = Object::create("images/blue.png", scene, 23600, 450);
	BNoteX[22] = 23600;
	BNote[23] = Object::create("images/blue.png", scene, 24240, 450);
	BNoteX[23] = 24240;
	BNote[24] = Object::create("images/blue.png", scene, 24880, 450);
	BNoteX[24] = 24880;
	BNote[25] = Object::create("images/blue.png", scene, 25120, 450);
	BNoteX[25] = 25120;
	BNote[26] = Object::create("images/blue.png", scene, 25280, 450);
	BNoteX[26] = 25280;
	BNote[27] = Object::create("images/blue.png", scene, 26160, 450);
	BNoteX[27] = 26160;
	BNote[28] = Object::create("images/blue.png", scene, 26800, 450);
	BNoteX[28] = 26800;
	BNote[29] = Object::create("images/blue.png", scene, 27440, 450);
	BNoteX[29] = 27440;
	BNote[30] = Object::create("images/blue.png", scene, 27600, 450);
	BNoteX[30] = 27600;
	BNote[31] = Object::create("images/blue.png", scene, 27680, 450);
	BNoteX[31] = 27680;
	RNote[40] = Object::create("images/red.png", scene, 28400, 450);
	RNoteX[40] = 28400;
	BNote[32] = Object::create("images/blue.png", scene, 28720, 450);
	BNoteX[32] = 28720;
	RNote[41] = Object::create("images/red.png", scene, 29040, 450);
	RNoteX[41] = 29040;
	BNote[33] = Object::create("images/blue.png", scene, 29360, 450);
	BNoteX[33] = 29360;
	RNote[42] = Object::create("images/red.png", scene, 29680, 450);
	RNoteX[42] = 29680;
	BNote[34] = Object::create("images/blue.png", scene, 30000, 450);
	BNoteX[34] = 30000;
	BNote[35] = Object::create("images/blue.png", scene, 30240, 450);
	BNoteX[35] = 30240;
	BNote[36] = Object::create("images/blue.png", scene, 30320, 450);
	BNoteX[36] = 30320;
	RNote[43] = Object::create("images/red.png", scene, 31200, 450);
	RNoteX[43] = 31200;
	RNote[44] = Object::create("images/red.png", scene, 31680, 450);
	RNoteX[44] = 31680;
	RNote[45] = Object::create("images/red.png", scene, 32160, 450);
	RNoteX[45] = 32160;
	RNote[46] = Object::create("images/red.png", scene, 32640, 450);
	RNoteX[46] = 32640;
	RNote[47] = Object::create("images/red.png", scene, 33120, 450);
	RNoteX[47] = 33120;
	BNote[37] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[37] = 50000;
	BNote[38] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[38] = 50000;
	BNote[39] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[39] = 50000;
	BNote[40] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[40] = 50000;
	BNote[41] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[41] = 50000;
	BNote[42] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[42] = 50000;
	BNote[43] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[43] = 50000;
	BNote[44] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[44] = 50000;
	BNote[45] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[45] = 50000;
	BNote[46] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[46] = 50000;
	BNote[47] = Object::create("images/blue.png", scene, 50000, 450);
	BNoteX[47] = 50000;

	auto startButton = Object::create("images/start.png", scene, 600, 220);
	startButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		auto startDelay = Timer::create(1.5f);
		startDelay->start();
		startButton->hide();

		startDelay->setOnTimerCallback([&](TimerPtr t)->bool {
			
			sound->play();
			
			return true;
		});

	auto endButton = Object::create("images/end.png", sceneEnd, 600, 220);
	endButton->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
		endGame();

			return true;
		});
		

		
			RNote[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[0]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});
				
				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[1]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[2]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[3]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});
			RNote[4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[4]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});
			RNote[5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[5]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});
			RNote[6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[6]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});
			RNote[7]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[7]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[8]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[8]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[9]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[9]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});
			RNote[10]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[10]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[11]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[11]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[12]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[12]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[13]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[13]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[14]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[14]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[15]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[15]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[16]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[16]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[17]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[17]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[18]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[18]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[19]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[19]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[20]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[20]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[21]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[21]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[22]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[22]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[23]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[23]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[24]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[24]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[25]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[25]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[26]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[26]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[27]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[27]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[28]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[28]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[29]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[29]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[30]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[30]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[31]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[31]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[32]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[32]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[33]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[33]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[34]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[34]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[35]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[35]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[36]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[36]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[37]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[37]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[38]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[38]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[39]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[39]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[40]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[40]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[41]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[41]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[42]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[42]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[43]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[43]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[44]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[44]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[45]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[45]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[46]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[46]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

			RNote[47]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				RNote[47]->hide();
				great->show();
				combo++;
				auto timerG = Timer::create(0.5f);
				timerG->start();
				timerG->setOnTimerCallback([&](TimerPtr t)->bool {
					great->hide();

					return true;
					});

				comboT->set(combo);
				showTimer(comboT);

				return true;
				});

		
			BNote[0]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[0]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);
				
				showTimer(comboT);

				return true;
				});
			
			BNote[1]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[1]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});
		
			BNote[2]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[2]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[3]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[3]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[4]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[4]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[5]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[5]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[6]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[6]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[7]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[7]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[8]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[8]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[9]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[9]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[10]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[10]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[11]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[11]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[12]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[12]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[13]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[13]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[14]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[14]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[15]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[15]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[16]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[16]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[17]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[17]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[18]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[18]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[19]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[19]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[20]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[20]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[21]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[21]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[22]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[22]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[23]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[23]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[24]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[24]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[25]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[25]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[26]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[26]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[27]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[27]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[28]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[28]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[29]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[29]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[30]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[30]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[31]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[31]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[32]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[32]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[33]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[33]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[34]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[34]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[35]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[35]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

			BNote[36]->setOnMouseCallback([&](ObjectPtr object, int x, int y, MouseAction action)->bool {
				BNote[36]->hide();
				combobreak->show();
				combo = 0;
				auto timerC = Timer::create(0.5f);
				timerC->start();
				timerC->setOnTimerCallback([&](TimerPtr t)->bool {
					combobreak->hide();

					return true;
					});
				comboT->set(combo);

				showTimer(comboT);

				return true;
				});

	

		timer->setOnTimerCallback([&](TimerPtr t)->bool {
		
			for (int i = 0; i < 48; i++) {
			
				BNoteX[i] = BNoteX[i] - 10;
				BNote[i]->locate(scene, BNoteX[i], 450);
				
				RNoteX[i] = RNoteX[i] - 10;
				RNote[i]->locate(scene, RNoteX[i], 450);
			}
			
			if (RNoteX[47] != 0) {
				timer->set(0.01f);
				timer->start();
			}
			else
			{
				sceneEnd->enter();
				
			}
			return true;
			});

		timer->start();
		return true;
	});


	
	startGame(scene);
		
	return 0;
}

