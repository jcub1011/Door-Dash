Put classes and their methods here.

IDEA: 
User selects options from a menu.
They can customize their selections EX: no onion, extra pickles etc...
They can view their cart to see what they picked, along with any customizations they made.
The can check out, where it will display the total cost (without tax or delivery fee) and items selected.
They can 'pay', and they will recieve a receipt with total cost + tax, delivery fee, and estimated arrival time. 

# class Item 
- private:
    - ***string*** *name*
      - Name of the item.
    - ***double*** *cost*
      - Price of the item.
    - ***map<string, double>*** *modifications*
      - Map of modifications made to the item and their respective price modifiers.

- public:
  - **item**(*name, base_price*)
      - Assigns the item a name and base price.
  - ***string*** **get_name**()
      - Retrives the name of the item.
  - ***void*** **add_modification**(*string modification, price_modifier*)
      - Adds the modification to the modifications map along with it's price modifier.
  - ***void*** **delete_modification**(*string modification*)
      - Removes the modification from the modifications map.
  - ***double*** **get_price**()
      - returns the current value of the item.

# class Menu 
- private:
  - ***map<string, double>*** *items*
      - Map of the items and their respective prices.
  - ***vector<Item>*** *
- public:
  - ***void*** **display_menu**()
      - Displays the menu.
  - ***void*** **pick_item**()
      - Prompts the user to pick an item and adds it to the map



class Restaurant {
vector<item> orders
void print_receipt
