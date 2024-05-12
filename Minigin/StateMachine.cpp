#include "StateMachine.h"

void dae::StateMachine::handleInput()
{
    State* state = m_State->handleInput(*m_GameObject);
    if (state != NULL)
    {
        delete m_State;
        m_State = state;

        // Call the enter action on the new state.
        m_State->enter(*m_GameObject);
    }
}
