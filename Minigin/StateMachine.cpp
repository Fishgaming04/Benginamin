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

void dae::StateMachine::update(GameObject& gameObject)
{
    State* state = m_State->update(gameObject);
    if (state != NULL)
    {
		m_State->exit(gameObject);
        delete m_State;
        m_State = state;

        // Call the enter action on the new state.
        m_State->enter(gameObject);
    }
}

void dae::StateMachine::SetState(State* state, GameObject& gameObject)
{
	if (m_State){
		m_State->exit(gameObject);
	}

	m_State = state;
    
    if (m_State) {
	    m_State->enter(gameObject);
    }
}

dae::State* dae::StateMachine::GetState()
{
    return m_State;
}

dae::StateMachine::~StateMachine()
{

}
