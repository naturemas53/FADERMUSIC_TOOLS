#pragma once
#include "../ESGLib.h"

class InputSingleton{

public:

	static InputSingleton& GetInstance(){

		static InputSingleton instance;

		return instance;

	}

	void Update(){
	
		this->key_buffer_ = Keyboard->GetBuffer();
		this->mouse_buffer_ = Mouse->GetBuffer();
		this->mouse_state_ = Mouse->GetState();

		if (mouse_state_.LeftButton != 0){
			this->mouseleft_pushtime_++;
		}
		else{
			this->mouseleft_pushtime_ = 0;
		}
	
	};

	bool IsKeyPressed(Keys key){ return this->key_buffer_.IsPressed(key); }
	bool IsKeyReleased(Keys key){ return this->key_buffer_.IsReleased(key); }
	bool IsMouseButtonPressed(DWORD mouse_button){ return this->mouse_buffer_.IsPressed(mouse_button); }
	bool IsMouseButtonReleased(DWORD mouse_button){ return this->mouse_buffer_.IsReleased(mouse_button); }
	bool IsMouseLeftButtonPush(){
	
		if (this->IsMouseButtonPressed(Mouse_Button1)){
			return true;
		}
		else if (this->mouseleft_pushtime_ >= 30 && this->mouseleft_pushtime_ % 5 == 0){

			return true;

		}

		return false;
	
	};

	LONG GetMouseXMove(){ return this->mouse_state_.X; }
	LONG GetMouseYMove(){ return this->mouse_state_.Y; }

	~InputSingleton() = default;

private:

	InputSingleton(){
	
		InputDevice.CreateMouse();
		this->mouseleft_pushtime_ = 0;
	
	};

	KeyboardBuffer key_buffer_;
	MouseBuffer mouse_buffer_;
	MouseState mouse_state_;

	int mouseleft_pushtime_;


};

#define StaticInput InputSingleton::GetInstance()