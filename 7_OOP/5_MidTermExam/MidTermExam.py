from typing import Any, List, Dict, Tuple

class Star_Cinema:
    def __init__(self) -> None:
        self.hall_list: List[Hall] = []

    def entry_hall(self, hall_no: int, rows: int, cols: int):
        self.hall_list.append(Hall(rows, cols, hall_no))


class Hall:
    def __init__(self, rows: int, cols: int, hall_no: int) -> None:
        self.__seats: Dict[str, List[List[bool]]] = {}
        self.__show_list: List[Tuple[str, str, str]] = []
        self.__rows = rows
        self.__cols = cols
        self.__hall_no = hall_no

    def entry_show(self, id: str, movie_name: str, time: str) -> str:
        self.__show_list.append((id, movie_name, time))
        SeatArray = [[False for _ in range(self.__cols)] for _ in range(self.__rows)]
        self.__seats[id] = SeatArray
        print('---------Show Entered Successfully---------')

    def book_seats(self, id: str, seats: List[Tuple[int, int]]):
        # Handling wrong ID
        if id not in self.__seats:
            print('Invalid ID')
            return
        #Handeling invalid seats
        for row, col in seats:
            if (row < 0 or row >= self.__rows) or (col < 0 or col >= self.__cols):
                print('----------------Invalid seat--------------')
                return
            # Handling already booked seats
            if self.__seats[id][row][col]:
                print(f'---------Seat at Row {row} and Col {col} was already booked-------')
            else:
                self.__seats[id][row][col] = True
                print(f'------------Seat at RowNo: {row} and ColNo: {col} Booked Successfully----------')

    def view_show_list(self):
        print("-------Show List------------")
        for id, movie, time in self.__show_list:
            print(f'ID: {id} Movie: {movie} Time: {time}')

    def view_available_seats(self, id: str):
        # Handling wrong ID
        if id not in self.__seats:
            print('Invalid ID')
            return
        print("-------Available Seats------------")
        # Available seats
        for row in range(self.__rows):
            for col in range(self.__cols):
                if not self.__seats[id][row][col]:
                    print(f'Available Seat - Row: {row} Col: {col}')


# Replica System Functions
def view_all_shows():
    for hall in cinema.hall_list:
        hall.view_show_list()


def available_show_list(id: str):
    for hall in cinema.hall_list:
        if any(show_id == id for show_id, _, _ in hall._Hall__show_list):
            hall.view_available_seats(id)
            break
    else:
        print("-----------Show is not in hall----------")


def book_tickets(id: str, seats: List[Tuple[int, int]]):
    for hall in cinema.hall_list:
        if any(show_id == id for show_id, _, _ in hall._Hall__show_list):
            hall.book_seats(id, seats)
            break
    else:
        print("----------------Show not found in hall----------")


# Example Usage
cinema = Star_Cinema()
cinema.entry_hall(1, 5, 5)
cinema.hall_list[0].entry_show('S1', 'Kalki', '10:00 AM')
cinema.hall_list[0].entry_show('S2', 'Kill', '02:00 PM')

view_all_shows()
available_show_list('S1')
book_tickets('S1', [(0, 0), (1, 1)])
available_show_list('S1')

