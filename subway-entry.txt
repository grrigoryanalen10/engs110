#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/* 
 * Subway Entry System using Finite State Machine
 * 
 * This program simulates a subway entry system with the following states:
 * - IDLE: Initial state, waiting for a passenger
 * - CARD_SCANNED: Passenger has scanned their card
 * - VALIDATING: System is validating the passenger's card
 * - ENTRY_GRANTED: Passenger is allowed to enter
 * - ENTRY_DENIED: Passenger is denied entry
 */

// Define states for the FSM
typedef enum {
    IDLE,
    CARD_SCANNED,
    VALIDATING,
    ENTRY_GRANTED,
    ENTRY_DENIED
} State;

// Define events that can cause state transitions
typedef enum {
    PASSENGER_APPROACHES,
    SCAN_CARD,
    VALID_CARD,
    INVALID_CARD,
    PASS_GATE,
    TIMEOUT
} Event;

// Define ticket types
typedef enum {
    REGULAR_TICKET,
    EXPIRED_TICKET,
    INVALID_TICKET
} TicketType;

// Function to get string representation of current state
const char* getStateName(State state) {
    switch (state) {
        case IDLE: return "IDLE";
        case CARD_SCANNED: return "CARD_SCANNED";
        case VALIDATING: return "VALIDATING";
        case ENTRY_GRANTED: return "ENTRY_GRANTED";
        case ENTRY_DENIED: return "ENTRY_DENIED";
        default: return "UNKNOWN";
    }
}

// Function to get string representation of event
const char* getEventName(Event event) {
    switch (event) {
        case PASSENGER_APPROACHES: return "PASSENGER_APPROACHES";
        case SCAN_CARD: return "SCAN_CARD";
        case VALID_CARD: return "VALID_CARD";
        case INVALID_CARD: return "INVALID_CARD";
        case PASS_GATE: return "PASS_GATE";
        case TIMEOUT: return "TIMEOUT";
        default: return "UNKNOWN";
    }
}

// Function to validate a ticket
bool validateTicket(TicketType ticket) {
    return ticket == REGULAR_TICKET;
}

// Main FSM function
State processEvent(State currentState, Event event, TicketType* ticketType) {
    printf("Processing event: %s in state: %s\n", getEventName(event), getStateName(currentState));
    
    // Define state transitions based on current state and event
    switch (currentState) {
        case IDLE:
            if (event == PASSENGER_APPROACHES) {
                printf("Passenger approaches the gate. Ready to scan card.\n");
                return IDLE;
            } else if (event == SCAN_CARD) {
                printf("Card scanned. Processing...\n");
                return CARD_SCANNED;
            }
            break;
            
        case CARD_SCANNED:
            if (event == VALIDATING) {
                printf("Validating card...\n");
                
                // Simulate card validation
                if (validateTicket(*ticketType)) {
                    *ticketType = REGULAR_TICKET;
                    return VALIDATING;
                } else {
                    printf("Invalid or expired card detected.\n");
                    return ENTRY_DENIED;
                }
            }
            break;
            
        case VALIDATING:
            if (event == VALID_CARD) {
                printf("Card validation successful. Entry granted!\n");
                return ENTRY_GRANTED;
            } else if (event == INVALID_CARD) {
                printf("Card validation failed. Entry denied!\n");
                return ENTRY_DENIED;
            }
            break;
            
        case ENTRY_GRANTED:
            if (event == PASS_GATE) {
                printf("Passenger has passed through the gate.\n");
                return IDLE;
            } else if (event == TIMEOUT) {
                printf("Passenger took too long to enter. Gate closed.\n");
                return IDLE;
            }
            break;
            
        case ENTRY_DENIED:
            if (event == TIMEOUT) {
                printf("Returning to idle state after denied entry.\n");
                return IDLE;
            }
            break;
    }
    
    // If no valid transition found, stay in current state
    printf("No valid transition for this event in current state. Staying in %s.\n", getStateName(currentState));
    return currentState;
}

// Function to simulate passenger entry scenarios
void simulateEntryScenarios() {
    State currentState = IDLE;
    Event events[] = {
        PASSENGER_APPROACHES,
        SCAN_CARD,
        VALIDATING,
        VALID_CARD,
        PASS_GATE,
        
        // Second passenger with invalid ticket
        PASSENGER_APPROACHES,
        SCAN_CARD,
        VALIDATING,
        INVALID_CARD,
        TIMEOUT,
        
        // Third passenger who times out after getting entry granted
        PASSENGER_APPROACHES,
        SCAN_CARD,
        VALIDATING,
        VALID_CARD,
        TIMEOUT
    };
    
    int numEvents = sizeof(events) / sizeof(events[0]);
    TicketType ticketTypes[] = {
        REGULAR_TICKET,   // First passenger has valid ticket
        EXPIRED_TICKET,   // Second passenger has expired ticket
        REGULAR_TICKET    // Third passenger has valid ticket but times out
    };
    
    int ticketIndex = 0;
    TicketType currentTicket;
    
    printf("\n=== SUBWAY ENTRY SYSTEM SIMULATION ===\n\n");
    
    for (int i = 0; i < numEvents; i++) {
        // Update ticket type at the start of each passenger scenario
        if (events[i] == PASSENGER_APPROACHES) {
            currentTicket = ticketTypes[ticketIndex++];
            printf("\n--- New Passenger (Ticket type: %s) ---\n", 
                  currentTicket == REGULAR_TICKET ? "REGULAR" : 
                  currentTicket == EXPIRED_TICKET ? "EXPIRED" : "INVALID");
        }
        
        // Process the current event
        currentState = processEvent(currentState, events[i], &currentTicket);
        
        printf("New state: %s\n", getStateName(currentState));
        printf("-----------------------------------------\n");
    }
}

int main() {
    // Run the simulation
    simulateEntryScenarios();
    
    return 0;
}