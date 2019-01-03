#pragma once

/* 
Ranking을 입출력으로 관리
가장 높은 점수 10개를 레코드로 관리함.
*/
class Ranking
{

private:

	Ranking();

	int mPlayerScore = 0;

	enum { SAVED_RECORD_NUMBER = 10 };

	struct Record
	{
		int RecordedScore = 0;
		char RecordedDate[30] = "empty";
	};

	Record mRecord[SAVED_RECORD_NUMBER];

	static Ranking* mInstance;

	const char* getCurrentDateTime();

	// 게임 종료 후, 자동으로 호출해 점수를 기록, 기록 후 LoadRangingData 호출해 화면에 점수 띄움
	void WriteRanking();

public:

	static Ranking* GetInstance()
	{
		if (mInstance == 0) {
			mInstance = new Ranking();
		}
		return mInstance;
	}

	// 게임 종료 후, 자동으로 호출해 기록된 점수를 읽어옴.
	void LoadRankingData();

	void AddPlayerScore(int score);

	inline void ResetPlayerScore() { mPlayerScore = 0; }

	inline int GetPlayerScore() const { return mPlayerScore; }

};
