import matplotlib.pyplot as plt
import os

current_dir = os.path.dirname(__file__)
PATH = os.path.join(current_dir, 'times.txt')

class Loader:
    def __init__(self, file_path: str):
        self.file_path = file_path
        self.n_values = []  # Количество вершин
        self.data_3_heap = []  
        self.data_15_heap = []  

    def load_data(self):
        with open(self.file_path, 'r') as file:
            for line in file:
                line = line.strip() 
                if line:  
                    n_str, times_str = line.split(':')  
                    n = int(n_str)  
                    times = list(map(float, times_str.split()))  
                    
                    self.n_values.append(n) 
                    if len(times) >= 2:
                        self.data_3_heap.append(times[0])  # Время для 3-Heap
                        self.data_15_heap.append(times[1])  # Время для 15-Heap

    def create_plot(self):
        if not self.n_values or not self.data_3_heap or not self.data_15_heap:
            return 'Нет данных! Сначала нужно выполнить метод load_data.'

        plt.plot(self.n_values, self.data_3_heap, label='3-Heap Dijkstra', marker='o')
        plt.plot(self.n_values, self.data_15_heap, label='15-Heap Dijkstra', marker='o')
        plt.xlabel('Максимальный вес ребра(r)')
        plt.ylabel('Время выполнения (сек.)')
        plt.title('Сравнение времени выполнения Dijkstra')
        plt.legend()
        plt.grid()
        plt.show()

l = Loader(PATH)
l.load_data()
l.create_plot()
l.clear_file()