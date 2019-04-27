<?php

$pdo = new \PDO('sqlite:/var/sqlite/ld44_highscores.sqlite3');
$pdo->setAttribute(\PDO::ATTR_ERRMODE, \PDO::ERRMODE_EXCEPTION);

$pdo->exec("CREATE TABLE IF NOT EXISTS HighScores (
    Id INTEGER,
    CurrentDateTime TEXT,
    RemoteIP TEXT,
    TimeToFinish REAL,
    LevelName TEXT,
    Upg0 INTEGER,
    Upg1 INTEGER,
    Upg2 INTEGER,
    Upg3 INTEGER,
    Upg4 INTEGER,
    Upg5 INTEGER,
    Upg6 INTEGER,
    Upg7 INTEGER,
    Upg8 INTEGER,
    Upg9 INTEGER
);");

$currentScoreId = mt_rand();

if (!empty($_POST['t']))
{
    $expectedC = substr(md5(
        $_POST['t'] .
        $_POST['l'] .
        $_POST['u0'] .
        $_POST['u1'] .
        $_POST['u2'] .
        $_POST['u3'] .
        $_POST['u4'] .
        $_POST['u5'] .
        $_POST['u6'] .
        $_POST['u7'] .
        $_POST['u8'] .
        $_POST['u9']), 0, 4);

    if ($_POST['c'] == $expectedC || 1)
    {
        $stmt = $pdo->prepare("INSERT INTO HighScores VALUES (?, ?, ?, ?, ?,  ?, ?, ?, ?, ?,  ?, ?, ?, ?, ?);");
        $stmt->execute([
            $currentScoreId,
            date(DATE_ISO8601),
            $_SERVER['REMOTE_ADDR'],
            $_POST['t'],
            $_POST['l'],

            $_POST['u0'],
            $_POST['u1'],
            $_POST['u2'],
            $_POST['u3'],
            $_POST['u4'],

            $_POST['u5'],
            $_POST['u6'],
            $_POST['u7'],
            $_POST['u8'],
            $_POST['u9']
        ]);
    }

    if ($_POST['c'] != $expectedC)
    {
        trigger_error('c was ' . ((int)$_POST['c']) . ' expected ' . $expectedC . ' ' . json_encode($_POST));
    }
}

header('Access-Control-Allow-Methods: POST, GET');
header('Access-Control-Allow-Origin: *');
header('Content-Type: application/json');

if ($_REQUEST['l'])
{
    $stmt = $pdo->prepare("SELECT (CASE Id WHEN ? THEN 1 ELSE 0 END) AS IsMyScore, TimeToFinish, Upg0, Upg1, Upg2, Upg3, Upg4, Upg5, Upg6, Upg7, Upg8, Upg9 FROM HighScores WHERE LevelName = ? ORDER BY TimeToFinish ASC;");

    $stmt->execute([$currentScoreId, $_REQUEST['l']]);

    echo json_encode($stmt->fetchAll(\PDO::FETCH_ASSOC));
}