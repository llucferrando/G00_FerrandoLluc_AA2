#pragma once
enum class DirectionType { Horizontal, Verticlal,Diagonal };

class Vector2D
{
public:
	int x, y;
	Vector2D(int x, int y) :x(x), y(y) {
	};
	static Vector2D* Horizontal()
	{
		return new Vector2D(1, 0);
	}
	static Vector2D* Vertical()
	{
		return new Vector2D(0, 1);
	}
	static Vector2D* Diagonal()
	{
		return new Vector2D(1, 1);
	}
	static Vector2D* GetDirectionFromType(DirectionType type)
	{
		switch (type)
		{
			case DirectionType::Horizontal:
				return Horizontal();
			case DirectionType::Verticlal:
				return Vertical();
			case DirectionType::Diagonal:
				return Diagonal();
		}

		return new Vector2D(0, 0);
	}
};

