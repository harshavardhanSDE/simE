import subprocess
import sys
import shutil
from pathlib import Path


def main():
    if not shutil.which("uv"):
        print("Error: uv is not installed")
        print("Install uv by: curl -LsFf https://astral.sh/uv/install.sh | sh")
        sys.exit(1)


root_dir = Path(__file__).parent
cli_dir = root_dir / "cli"
cli_script = cli_dir / "main.py"

cmd = [
    "uv",
    "run",
    "--project", str(cli_dir),
    str(cli_script)
] + sys.argv[1:]


try:
    subprocess.run(cmd, check=True)
except subprocess.CalledProcessError as err:
    sys.exit(err.returncode)
except KeyboardInterrupt:
    sys.exit(130)

if __name__ == "__main__":
    main()
