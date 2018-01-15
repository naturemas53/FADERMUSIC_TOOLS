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
	
	};

	bool IsKeyPressed(Keys key){ return this->key_buffer_.IsPressed(key); }
	bool IsKeyReleased(Keys key){ return this->key_buffer_.IsReleased(key); }
	bool IsMouseButtonPressed(DWORD mouse_button){ return this->mouse_buffer_.IsPressed(mouse_button); }
	bool IsMouseButtonReleased(DWORD mouse_button){ return this->mouse_buffer_.IsReleased(mouse_button); }

	LONG GetMouseXMove(){ return this->mouse_state_.X; }
	LONG GetMouseYMove(){ return this->mouse_state_.Y; }

	~InputSingleton() = default;

private:

	InputSingleton(){
	
		InputDevice.CreateMouse();
	
	};

	KeyboardBuffer key_buffer_;
	MouseBuffer mouse_buffer_;
	MouseState mouse_state_;

};

#define StaticInput InputSingleton::GetInstance()