CREATE TABLE users (
    user_id INT AUTO_INCREMENT PRIMARY KEY,
    user_name VARCHAR(255) NOT NULL,
    user_email VARCHAR(255) UNIQUE,
    password_hash VARCHAR(255) NOT NULL,
    user_type ENUM('normal', 'teacher', 'expert') NOT NULL,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    INDEX idx_user_email (user_email)
);

CREATE TABLE user_details (
    detail_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    qualification TEXT,
    experience INT,
    specialty VARCHAR(255),
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE,
    UNIQUE (user_id) -- Ensuring one-to-one relationship
);

CREATE TABLE conversations (
    conversation_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    title VARCHAR(255),
    started_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE,
    INDEX idx_user_id (user_id)
);

CREATE TABLE messages (
    message_id INT AUTO_INCREMENT PRIMARY KEY,
    conversation_id INT NOT NULL,
    sender ENUM('user', 'chatbot') NOT NULL,
    text TEXT NOT NULL,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (conversation_id) REFERENCES conversations(conversation_id) ON DELETE CASCADE,
    INDEX idx_conversation_id (conversation_id)
);


CREATE TABLE feedback (
    feedback_id INT AUTO_INCREMENT PRIMARY KEY,
    user_id INT NOT NULL,
    conversation_id INT NOT NULL,
    message_id INT NOT NULL,
    feedback_text TEXT,
    rating INT,
    timestamp TIMESTAMP DEFAULT CURRENT_TIMESTAMP,
    FOREIGN KEY (user_id) REFERENCES users(user_id) ON DELETE CASCADE,
    FOREIGN KEY (conversation_id) REFERENCES conversations(conversation_id) ON DELETE CASCADE,
    FOREIGN KEY (message_id) REFERENCES messages(message_id) ON DELETE CASCADE,
    INDEX idx_user_id (user_id),
    INDEX idx_conversation_id (conversation_id),
    INDEX idx_message_id (message_id)
);
