Laboratorio 4 - Patrones de diseño en entrevistas técnicas

1. Investigación: Preguntas de entrevistas técnicas

Pregunta 1: "¿Cómo diseñarías un sistema de logging global en una aplicación?"
Contexto: Necesitamos un sistema de registro de eventos (logging) que esté disponible en toda la aplicación y que garantice que todas las partes del sistema escriban en el mismo archivo de log.

Pregunta 2: "¿Cómo modelarías una aplicación que necesita múltiples algoritmos intercambiables para procesamiento de pagos?"
Contexto: Un sistema de e-commerce necesita soportar diferentes métodos de pago (PayPal, tarjeta de crédito, transferencia bancaria) con la posibilidad de añadir nuevos métodos fácilmente.

Pregunta 3: "¿Cómo construirías una interfaz para distintos sistemas operativos sin acoplarte a uno específico?"
Contexto: Desarrollar una aplicación multiplataforma que funcione en Windows, macOS y Linux, pero que el código cliente no dependa de implementaciones específicas para cada SO.

2. Análisis y aplicación de patrones

Pregunta 1: Sistema de logging global
Problema: Necesitamos una única instancia de logger accesible globalmente que maneje todas las operaciones de registro.

Patrón propuesto: Singleton

Justificación:
Singleton garantiza que solo exista una instancia de la clase Logger
Proporciona un punto de acceso global a esta instancia
Evita la creación múltiple de objetos Logger que podrían generar inconsistencias

Implementación en Python:
class Logger:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super(Logger, cls).__new__(cls)
            cls._instance.log_file = open('app.log', 'a')
        return cls._instance

    def log(self, message):
        self.log_file.write(f"{message}\n")
        self.log_file.flush()

# Uso
logger = Logger()
logger.log("Este es un mensaje de log")

Pregunta 2: Algoritmos intercambiables para procesamiento de pagos
Problema: Necesitamos poder cambiar el algoritmo de procesamiento de pagos en tiempo de ejecución sin modificar el código que lo usa.

Patrón propuesto: Strategy

Justificación:
Strategy permite encapsular cada algoritmo de pago en una clase separada
Hace fácil añadir nuevos métodos de pago sin modificar el código existente
Permite cambiar el algoritmo usado en tiempo de ejecución

Implementación en Python:
from abc import ABC, abstractmethod

class PaymentStrategy(ABC):
    @abstractmethod
    def pay(self, amount):
        pass

class CreditCardPayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Pagando {amount} con tarjeta de crédito")

class PayPalPayment(PaymentStrategy):
    def pay(self, amount):
        print(f"Pagando {amount} con PayPal")

class PaymentContext:
    def __init__(self, strategy: PaymentStrategy):
        self._strategy = strategy
    
    def execute_payment(self, amount):
        self._strategy.pay(amount)

# Uso
payment = PaymentContext(CreditCardPayment())
payment.execute_payment(100)  # Pagando 100 con tarjeta de crédito

payment = PaymentContext(PayPalPayment())
payment.execute_payment(50)  # Pagando 50 con PayPal

Pregunta 3: Interfaz para distintos sistemas operativos
Problema: Necesitamos una abstracción común para funcionalidades específicas de cada sistema operativo.

Patrón propuesto: Abstract Factory

Justificación:
Abstract Factory proporciona una interfaz para crear familias de objetos relacionados
Oculta las implementaciones específicas de cada sistema operativo
Facilita la adición de soporte para nuevos sistemas operativos

Implementación en Python:
from abc import ABC, abstractmethod

# Abstract Factory
class GUIFactory(ABC):
    @abstractmethod
    def create_button(self):
        pass
    
    @abstractmethod
    def create_checkbox(self):
        pass

# Concrete Factories
class WindowsFactory(GUIFactory):
    def create_button(self):
        return WindowsButton()
    
    def create_checkbox(self):
        return WindowsCheckbox()

class MacOSFactory(GUIFactory):
    def create_button(self):
        return MacOSButton()
    
    def create_checkbox(self):
        return MacOSCheckbox()

# Abstract Products
class Button(ABC):
    @abstractmethod
    def render(self):
        pass

class Checkbox(ABC):
    @abstractmethod
    def render(self):
        pass

# Concrete Products
class WindowsButton(Button):
    def render(self):
        print("Renderizando botón al estilo Windows")

class MacOSButton(Button):
    def render(self):
        print("Renderizando botón al estilo macOS")

class WindowsCheckbox(Checkbox):
    def render(self):
        print("Renderizando checkbox al estilo Windows")

class MacOSCheckbox(Checkbox):
    def render(self):
        print("Renderizando checkbox al estilo macOS")

# Cliente
class Application:
    def __init__(self, factory: GUIFactory):
        self.factory = factory
    
    def create_ui(self):
        button = self.factory.create_button()
        checkbox = self.factory.create_checkbox()
        button.render()
        checkbox.render()

# Uso
app = Application(WindowsFactory())
app.create_ui()
# Output:
# Renderizando botón al estilo Windows
# Renderizando checkbox al estilo Windows

3. Reflexión
Este laboratorio me ha permitido comprender mejor cómo los patrones de diseño resuelven problemas comunes en el desarrollo de software de manera elegante y mantenible. En particular:

Singleton es ideal para recursos compartidos como logging, pero debe usarse con cuidado para no crear dependencias ocultas.

Strategy ofrece una solución flexible para algoritmos intercambiables, promoviendo el principio de abierto/cerrado.

Abstract Factory es poderoso para crear familias de objetos relacionados, especialmente en aplicaciones multiplataforma.

Los patrones de diseño no son soluciones mágicas, sino herramientas que, cuando se aplican correctamente en el contexto adecuado, pueden simplificar significativamente la arquitectura del software. La clave está en reconocer el problema subyacente y seleccionar el patrón que mejor se adapte, en lugar de forzar el uso de patrones donde no son necesarios.

Este ejercicio también me hizo apreciar cómo estas soluciones son valoradas en entrevistas técnicas, ya que demuestran no solo conocimiento técnico, sino también la capacidad de pensar en problemas de diseño a un nivel más abstracto.