BEGIN TRANSACTION;
CREATE TABLE IF NOT EXISTS products (
  id INTEGER PRIMARY KEY NOT NULL CHECK (id < 10000000000000 and (10 - (((id / 1000000000000 % 10) + (id / 100000000000 % 10) * 3 + (id / 10000000000 % 10) + (id / 1000000000 % 10) * 3 + (id / 100000000 % 10) + (id / 10000000 % 10) * 3 + (id / 1000000 % 10) + (id / 100000 % 10) * 3 + (id / 10000 % 10) + (id / 1000 % 10) * 3 + (id / 100 % 10) + (id / 10 % 10) * 3) % 10)) % 10 == (id / 1 % 10)),
  name TEXT,
  amount INTEGER NOT NULL DEFAULT 0,
  category INTEGER REFERENCES categories,
  deprecated BOOLEAN NOT NULL DEFAULT 0,
  max INTEGER NOT NULL DEFAULT 1,
  threshold INTEGER NOT NULL DEFAULT 0,
  notify INTEGER NOT NULL DEFAULT 0,
  vpe INTEGER NOT NULL DEFAULT 1,
  supplier INTEGER REFERENCES supplier,
  supplier_number TEXT
);

CREATE TABLE IF NOT EXISTS sales (
  user INTEGER NOT NULL REFERENCES users,
  product INTEGER NOT NULL REFERENCES products,
  timestamp INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS restock_new (
  user INTEGER NOT NULL REFERENCES users,
  product INTEGER NOT NULL REFERENCES products,
  amount INTEGER NOT NULL DEFAULT 0,
  timestamp INTEGER NOT NULL DEFAULT 0,
  price INTEGER NOT NULL DEFAULT 0,
  supplier INTEGER REFERENCES supplier,
  best_before_date INTEGER,
  order_id INTEGER REFERENCES orders
);

CREATE TABLE IF NOT EXISTS prices (
  product INTEGER NOT NULL REFERENCES products,
  valid_from INTEGER NOT NULL DEFAULT 0,
  memberprice INTEGER NOT NULL DEFAULT 0,
  guestprice INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS users (
  id INTEGER PRIMARY KEY NOT NULL,
  email TEXT,
  firstname TEXT NOT NULL,
  lastname TEXT NOT NULL,
  gender TEXT,
  street TEXT,
  plz INTEGER,
  city TEXT,
  pgp TEXT,
  disabled BOOLEAN NOT NULL DEFAULT 0,
  hidden BOOLEAN NOT NULL DEFAULT 0,
  sound_theme TEXT,
  language TEXT,
  joined_at INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS authentication(
  user INTEGER PRIMARY KEY NOT NULL REFERENCES users,
  password TEXT,
  pin TEXT,
  session CHARACTER(20),
  superuser BOOLEAN NOT NULL DEFAULT 0,
  auth_users BOOLEAN NOT NULL DEFAULT 0,
  auth_products BOOLEAN NOT NULL DEFAULT 0,
  auth_cashbox BOOLEAN NOT NULL DEFAULT 0,
  disabled BOOLEAN NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS supplier_new (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name TEXT,
  city TEXT,
  postal_code TEXT,
  street TEXT,
  phone TEXT,
  website TEXT,
  supplier_number TEXT,
  customer_number TEXT,
  order_format TEXT,
  order_transport TEXT
);

CREATE TABLE IF NOT EXISTS cashbox_diff(
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  user INTEGER NOT NULL REFERENCES users,
  amount INTEGER NOT NULL,
  timestamp INTEGER NOT NULL DEFAULT 0
);

CREATE TABLE IF NOT EXISTS ean_aliases (
  id INTEGER PRIMARY KEY NOT NULL,
  real_ean INTEGER NOT NULL REFERENCES products
);

CREATE TABLE IF NOT EXISTS categories (
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  name TEXT
);

CREATE TABLE IF NOT EXISTS rfid_users (
  rfid TEXT,
  user INTEGER NOT NULL REFERENCES users
);

CREATE TABLE IF NOT EXISTS orders
(
  id INTEGER PRIMARY KEY AUTOINCREMENT,
  product INTEGER NOT NULL REFERENCES products,
  amount INTEGER NOT NULL,
  created_at INTEGER NOT NULL,
  orderd_at INTEGER,
  received_at INTEGER,
  supplier INTEGER NOT NULL REFERENCES supplier
);

CREATE INDEX IF NOT EXISTS invoiceindex ON sales (user ASC, timestamp DESC);

COMMIT;
