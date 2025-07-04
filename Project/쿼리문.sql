-- 기존 DB가 있으면 삭제
DROP DATABASE IF EXISTS distanceDB;

-- 새로 생성
CREATE DATABASE distanceDB;
USE distanceDB;

-- 테이블이 있으면 삭제
DROP TABLE IF EXISTS distance_log;

-- 테이블 생성
CREATE TABLE distance_log (
    id INT AUTO_INCREMENT PRIMARY KEY,
    log_time TIMESTAMP DEFAULT CURRENT_TIMESTAMP,  -- 시간 자동 기록
    distance_cm FLOAT NOT NULL,                    -- 측정 거리 (cm)
    warning_status VARCHAR(10) NOT NULL            -- 경고 여부 ("경고" or "정상")
);

-- 확인용 쿼리
SELECT * FROM distance_log ORDER BY log_time DESC;
