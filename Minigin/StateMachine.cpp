#include "StateMachine.h"

//void dae::StateMachine::handleInput(GameObject& gameObject)
//{
//    State* state = m_State->handleInput(gameObject);
//    if (state != NULL)
//    {
//        delete m_State;
//        m_State = state;
//
//        // Call the enter action on the new state.
//        m_State->enter(gameObject);
//    }
//}

void dae::StateMachine::update()
{
    State* state = m_State->update(*GetGameObject());
    if (state != NULL)
    {
		m_State->exit(*GetGameObject());
        delete m_State;
        m_State = state;

        // Call the enter action on the new state.
        m_State->enter(*GetGameObject());
    }
}

void dae::StateMachine::SetState(State* state)
{
	if (m_State){
		m_State->exit(*GetGameObject());
	}

	m_State = state;
    
    if (m_State) {
	    m_State->enter(*GetGameObject());
    }
}

dae::State* dae::StateMachine::GetState()
{
    return m_State;
}

dae::StateMachine::~StateMachine()
{

}
